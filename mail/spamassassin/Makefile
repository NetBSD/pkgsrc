# $NetBSD: Makefile,v 1.31 2003/09/13 17:57:21 jlam Exp $

DISTNAME=	Mail-SpamAssassin-2.55
PKGNAME=	spamassassin-2.55
PKGREVISION=	2
SVR4_PKGNAME=	sa
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}			\
		http://www.spamassassin.org/released/

MAINTAINER=	heinz-sa@NetBSD.org
HOMEPAGE=	http://www.spamassassin.org/
COMMENT=	Mail filter to identify spam

CONFLICTS=	p5-Mail-SpamAssassin-[1-9]*

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.perl=	perl>=5.6.0

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=	p5-HTML-Parser>=3.0:../../www/p5-HTML-Parser
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-MIME-Base64>=2.11:../../converters/p5-MIME-Base64
.if ${OPSYS} == "SunOS"
DEPENDS+=	p5-DB_File-[0-9]*:../../databases/p5-DB_File
.endif

ALL_TARGET=		all

SPAMASSASSIN_USE_SSL?=	NO
BUILD_DEFS+=		SPAMASSASSIN_USE_SSL

.if !empty(SPAMASSASSIN_USE_SSL:M[yY][eE][sS])
.  include "../../security/openssl/buildlink2.mk"
DEPENDS+=		p5-IO-Socket-SSL>=0.92:../../security/p5-IO-Socket-SSL
CONFIGURE_ARGS+=	--enable-ssl
ALL_TARGET+=		spamd/sslspamc
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
PKG_SYSCONFSUBDIR=	spamassassin

PLIST_ADD=		${WRKSRC}/.PLIST_ADD
PLIST_SRC=		${PKGDIR}/PLIST ${PLIST_ADD}
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/SpamAssassin/.packlist

GNU_CONFIGURE=		YES
PERL5_CONFIGURE=	NO
MAKE_PARAMS=		SYSCONFDIR="${PKG_SYSCONFDIR}"
MAKE_PARAMS+=		LOCAL_RULES_DIR="${PKG_SYSCONFDIR}"
MAKE_PARAMS+=		RUN_RAZOR1_TESTS="y" RUN_RAZOR2_TESTS="y"

OWN_DIRS+=		${PKG_SYSCONFDIR}/certs

RCD_SCRIPTS=		spamd
RCD_SCRIPT_SRC.spamd=	${WRKDIR}/${DISTNAME}/spamd/netbsd-rc-script.sh

EGDIR=			${PREFIX}/share/examples/spamassassin
DOCDIR=			${PREFIX}/share/doc/spamassassin
DOC_SUBDIR=		${DOCDIR:S,^${PREFIX}/,,}
HTMLDIR=		${PREFIX}/share/doc/html/spamassassin
RULESDIR=		${PREFIX}/share/spamassassin

CONF_FILES+=		${EGDIR}/local.cf ${PKG_SYSCONFDIR}/local.cf
CONF_FILES+=		${PREFIX}/share/spamassassin/user_prefs.template \
			  ${PKG_SYSCONFDIR}/user_prefs.template
SUPPORT_FILES_PERMS+=	${EGDIR}/netbsd_lists.cf			\
			  ${PKG_SYSCONFDIR}/netbsd_lists.cf ${SHAREOWN}	\
			  ${SHAREGRP} ${SHAREMODE}

.if ${OPSYS} == "NetBSD"
#  the 'spamd' RCD_SCRIPT behaves differently if we run NetBSD 1.6 or later
.  if ${OS_VERSION:M1.[0-5]*}
INTERPRETER_SUPPORT=	NO
.  else
INTERPRETER_SUPPORT=	YES
.  endif
.endif

# These values are substituted into netbsd-rc-script.sh.
FILES_SUBST+=	INTERPRETER_SUPPORT="${INTERPRETER_SUPPORT}"
FILES_SUBST+=	OPSYS="${OPSYS}"

post-extract:
	@# correct bad SA permissions
	@${CHMOD} a-x ${WRKSRC}/License
	@${CHMOD} a-x ${WRKSRC}/lib/Mail/SpamAssassin/*.pm
	@${CHMOD} a-x ${WRKSRC}/rules/20_uri_tests.cf
	@${CHMOD} a+x ${WRKSRC}/masses/uniq-scores
	@${CHMOD} a+x ${WRKSRC}/tools/translation_prep.pl

post-patch:
.for f in INSTALL README USAGE lib/Mail/SpamAssassin/Conf.pm		\
		spamd/README.spamd spamd/README.spamd-vpopmail sql/README
	@${SED}	-e "s,/usr/share,${PREFIX}/share,g"			\
		-e "s,/usr/bin,${PREFIX}/bin,g"				\
		-e "s,/usr/lib,${PREFIX}/lib,g"				\
		-e "s,/etc/mail/spamassassin,${PKG_SYSCONFDIR},g"	\
		${WRKSRC}/${f} > ${WRKSRC}/${f}.fixed;			\
	${MV} ${WRKSRC}/${f}.fixed ${WRKSRC}/${f}
.endfor

pre-configure: perl5-configure

pre-install:
	@-${TEST} -r ${PLIST_ADD} && ${RM} ${PLIST_ADD} ; :
	@${INSTALL_DATA_DIR} ${EGDIR}
	@${INSTALL_DATA_DIR} ${DOCDIR}/spamd
	@${INSTALL_DATA_DIR} ${HTMLDIR}
	@# ninja image is in the static PLIST
	@${INSTALL_DATA} ${WRKSRC}/ninjabutton.png ${HTMLDIR}/
.for f in CONTRIB_CERT COPYRIGHT INSTALL License README TRADEMARK USAGE	\
		sample-nonspam.txt sample-spam.txt spamd/README.spamd	\
		spamd/README.spamd-vpopmail
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}/$f
	@${ECHO} "${DOC_SUBDIR}/$f" >> ${PLIST_ADD}
.endfor
	@${ECHO} "@dirrm ${DOC_SUBDIR}/spamd" >> ${PLIST_ADD}
.for f in STATISTICS.txt STATISTICS-set1.txt STATISTICS-set2.txt	\
		STATISTICS-set3.txt
	@${INSTALL_DATA} ${WRKSRC}/rules/$f ${DOCDIR}/
	@${ECHO} "${DOC_SUBDIR}/$f" >> ${PLIST_ADD}
.endfor
.for DIR in masses qmail sql tools
	@cd ${WRKSRC};							\
	for d in `${FIND} ${DIR} -type d -print`; do			\
		${INSTALL_DATA_DIR} ${DOCDIR}/$$d;			\
	done;								\
	for f in `${FIND} ${DIR} -type f -print`; do			\
		if ${TEST} -f $$f; then					\
			: ;						\
		else							\
			continue;					\
		fi;							\
		if ${TEST} -x $$f ; then				\
			${SED}	-e "1s,/usr/bin/perl,${PERL5},"		\
				-e "1s,/usr/local/bin/perl,${PERL5},"	\
				$$f > $${f}.fixed;			\
			${MV} $${f}.fixed $$f;				\
			${CHMOD} +x $$f;				\
			${INSTALL_SCRIPT} $$f ${DOCDIR}/$$f;		\
		else							\
			${INSTALL_DATA} $$f ${DOCDIR}/$$f;		\
		fi;							\
		${ECHO} "${DOC_SUBDIR}/$$f" >> ${PLIST_ADD};		\
	done;								\
	(for d in `${FIND} ${DIR} -type d -print`; do			\
		${ECHO} "@dirrm ${DOC_SUBDIR}/$$d";			\
	done) | ${SORT} -r >> ${PLIST_ADD}
.endfor
	@${ECHO} "@dirrm ${DOC_SUBDIR}" >> ${PLIST_ADD}
	@cd ${WRKSRC}/rules;						\
	for f in [0-9]*.cf; do						\
		${ECHO} "share/spamassassin/$$f" >> ${PLIST_ADD};	\
	done
	@${ECHO} "@dirrm share/spamassassin" >> ${PLIST_ADD}
	@# examples are in the static PLIST
	@${INSTALL_DATA} ${WRKSRC}/procmailrc.example ${EGDIR}/
	@${INSTALL_DATA} ${WRKSRC}/rules/local.cf ${EGDIR}/
	@${INSTALL_DATA} ${FILESDIR}/netbsd_lists.cf ${EGDIR}/

post-install:
	@${CHOWN} ${SHAREOWN} ${RULESDIR}/*
	@${CHGRP} ${SHAREGRP} ${RULESDIR}/*
	@${CHMOD} a=r ${RULESDIR}/*
.if !empty(SPAMASSASSIN_USE_SSL:M[yY][eE][sS])
	@${INSTALL_PROGRAM} ${WRKSRC}/spamd/sslspamc ${PREFIX}/bin/
	@${ECHO} "bin/sslspamc" >> ${PLIST_ADD}
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
