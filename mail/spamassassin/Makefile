# $NetBSD: Makefile,v 1.48 2004/10/03 00:12:54 tv Exp $

DISTNAME=	Mail-SpamAssassin-${SPAMASSASSIN_VERSION}
PKGNAME=	spamassassin-${SPAMASSASSIN_VERSION}
PKGREVISION=	#1
SVR4_PKGNAME=	sa
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}			\
		http://old.spamassassin.org/released/

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://www.spamassassin.org/
COMMENT=	Mail filter to identify spam

CONFLICTS=	p5-Mail-SpamAssassin-[1-9]*

SPAMASSASSIN_VERSION=	2.64

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

PERL5_REQD+=	5.6.0	# MakeMaker >= 5.45 needed

DEPENDS+=	p5-Net-DNS>=0.29:../../net/p5-Net-DNS
DEPENDS+=	p5-HTML-Parser>=3.29:../../www/p5-HTML-Parser
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-MIME-Base64>=2.11:../../converters/p5-MIME-Base64
.if ${OPSYS} == "SunOS"
DEPENDS+=	p5-DB_File-[0-9]*:../../databases/p5-DB_File
.endif

SPAMASSASSIN_USE_SSL?=	YES

.if !empty(SPAMASSASSIN_USE_SSL:M[yY][eE][sS])
.  include "../../security/openssl/buildlink3.mk"
DEPENDS+=		p5-IO-Socket-SSL>=0.92:../../security/p5-IO-Socket-SSL
CONFIGURE_ARGS+=	--enable-ssl
MAKE_PARAMS=		ENABLE_SSL=yes
SA_SSLCERTS=		${SSLCERTS}
.else
CONFIGURE_ARGS+=	--disable-ssl
MAKE_PARAMS=		ENABLE_SSL=no
SA_SSLCERTS=		'$$LOCAL_RULES_DIR/certs'
.endif

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
PKG_SYSCONFSUBDIR=	spamassassin

# Set contact address (e-mail, URL, ...) for use in spam report messages
# See "perldoc Mail::SpamAssassin::Conf" for option "report_contact" 
SPAMASSASSIN_CONTACT_ADDRESS?=		'the administrator of that system'

# Use "NO" to turn off warnings and taint checks in spamd/spamassassin
SPAMASSASSIN_PERL_WARNINGS?=		YES
SPAMASSASSIN_PERL_TAINT_CHECKS?=	YES

# Enable test for Razor during 'make test'?
SPAMASSASSIN_RAZOR_TESTS?=		YES

BUILD_DEFS+=		SPAMASSASSIN_USE_SSL
BUILD_DEFS+=		SPAMASSASSIN_CONTACT_ADDRESS
BUILD_DEFS+=		SPAMASSASSIN_PERL_WARNINGS
BUILD_DEFS+=		SPAMASSASSIN_PERL_TAINT_CHECKS

PLIST_ADD=		${WRKSRC}/.PLIST_ADD
PLIST_SRC=		${PKGDIR}/PLIST ${PLIST_ADD}
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/SpamAssassin/.packlist

GNU_CONFIGURE=		YES
CONFIGURE_DIRS=		${WRKSRC}/spamd
PERL5_CONFIGURE=	NO # we need the default "do-configure" target
PERL5_CONFIGURE_DIRS=	${WRKSRC}

MAKE_PARAMS+=		SYSCONFDIR="${PKG_SYSCONFDIR}"
MAKE_PARAMS+=		LOCALRULESDIR="${PKG_SYSCONFDIR}"
MAKE_PARAMS+=		DEFRULESDIR="${RULESDIR}"
MAKE_PARAMS+=		RUN_RAZOR_TESTS="${SPAMASSASSIN_RAZOR_TESTS}"
MAKE_PARAMS+=		PERL_WARN="${SPAMASSASSIN_PERL_WARNINGS}"
MAKE_PARAMS+=		PERL_TAINT="${SPAMASSASSIN_PERL_TAINT_CHECKS}"

RCD_SCRIPTS=		spamd
RCD_SCRIPT_SRC.spamd=	${WRKSRC}/spamd/netbsd-rc-script.sh

EGDIR=			${PREFIX}/share/examples/spamassassin
EG_SUBDIR=		${EGDIR:S,^${PREFIX}/,,}
DOCDIR=			${PREFIX}/share/doc/spamassassin
DOC_SUBDIR=		${DOCDIR:S,^${PREFIX}/,,}
HTMLDIR=		${PREFIX}/share/doc/html/spamassassin
HTML_SUBDIR=		${HTMLDIR:S,^${PREFIX}/,,}
RULESDIR=		${PREFIX}/share/spamassassin
RULE_SUBDIR=		${RULESDIR:S,^${PREFIX}/,,}

CONF_FILES+=		${EGDIR}/local.cf  ${PKG_SYSCONFDIR}/local.cf	\
			${RULESDIR}/user_prefs.template			\
		 	${PKG_SYSCONFDIR}/user_prefs.template
SUPPORT_FILES_PERMS+=	${EGDIR}/netbsd_lists.cf			\
			${PKG_SYSCONFDIR}/netbsd_lists.cf ${SHAREOWN}	\
			${SHAREGRP} ${SHAREMODE}

INSTALLATION_DIRS+=	${EG_SUBDIR} ${DOC_SUBDIR} ${DOC_SUBDIR}/spamd	\
			${HTML_SUBDIR}

DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL

SUBST_CLASSES+=		sa1 sa2 sa3

SUBST_STAGE.sa1=	post-patch
SUBST_FILES.sa1=	Makefile.PL
SUBST_SED.sa1=		-e s!@SA_CONTACT_ADDRESS@!${SPAMASSASSIN_CONTACT_ADDRESS}!

SUBST_STAGE.sa2=	post-patch
SUBST_FILES.sa2=	README spamd/spamd.raw
SUBST_SED.sa2=		-e s!@@PREFIX@@!${PREFIX}!g			\
			-e s!@PKG_SYSCONFDIR@!${PKG_SYSCONFDIR}!g	\
			-e s!@SA_SSLCERTS@!${SA_SSLCERTS}!g

SUBST_STAGE.sa3=	post-patch
SUBST_FILES.sa3=	INSTALL USAGE lib/Mail/SpamAssassin/Conf.pm	\
			spamd/README.spamd spamd/README.spamd-vpopmail	\
			sql/README
SUBST_SED.sa3=		-e s!/usr/share!${PREFIX}/share!g		\
			-e s!/usr/bin!${PREFIX}/bin!g			\
			-e s!/usr/lib!${PREFIX}/lib!g			\
			-e s!/etc/mail/spamassassin!${PKG_SYSCONFDIR}!g

.if ${OPSYS} == "NetBSD"
#  the 'spamd' RCD_SCRIPT behaves differently if we run NetBSD 1.6 or later
.  if ${OS_VERSION:M1.[0-5]*}
INTERPRETER_SUPPORT=	NO
.  else
INTERPRETER_SUPPORT=	YES
.  endif
.endif

# These values are substituted into netbsd-rc-script.sh.
FILES_SUBST+=		INTERPRETER_SUPPORT="${INTERPRETER_SUPPORT}"
FILES_SUBST+=		OPSYS="${OPSYS}"

post-extract:
	@# correct bad SA permissions
	@${CHMOD} a-x ${WRKSRC}/License
	@${CHMOD} a-x ${WRKSRC}/lib/Mail/SpamAssassin/*.pm
	@${CHMOD} a-x ${WRKSRC}/rules/20_uri_tests.cf
	@${CHMOD} a+x ${WRKSRC}/masses/uniq-scores
	@${CHMOD} a+x ${WRKSRC}/tools/translation_prep.pl

pre-configure: perl5-configure

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

post-install:
	@${TEST} -r ${PLIST_ADD} && ${RM} ${PLIST_ADD} ; :
	@ # ninja image is in the static PLIST
	@${INSTALL_DATA} ${WRKSRC}/ninjabutton.png ${HTMLDIR}/
.for f in CONTRIB_CERT COPYRIGHT INSTALL License README TRADEMARK USAGE	\
		sample-nonspam.txt sample-spam.txt spamd/README.spamd	\
		spamd/README.spamd-vpopmail
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}/$f
	@${ECHO} "${DOC_SUBDIR}/$f" >> ${PLIST_ADD}
.endfor
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
			: ; 						\
		else							\
			continue;					\
		fi;							\
		if ${TEST} -x $$f ; then				\
			${SED} -e "1s,#!.*/bin/perl,#!${PERL5}," < $$f	\
				> $${f}.fixed &&			\
			${MV} $${f}.fixed $$f &&			\
			${CHMOD} +x $$f &&				\
			${INSTALL_SCRIPT} $$f ${DOCDIR}/$$f;		\
		else							\
			${INSTALL_DATA} $$f ${DOCDIR}/$$f;		\
		fi;							\
		${ECHO} "${DOC_SUBDIR}/$$f" >> ${PLIST_ADD};		\
	done;								\
	{ for d in `${FIND} ${DIR} -type d -print`; do			\
		${ECHO} "@dirrm ${DOC_SUBDIR}/$$d";			\
	done; } | ${SORT} -r >> ${PLIST_ADD};
.endfor
	@cd ${WRKSRC}/rules;						\
	for f in [0-9]*.cf; do						\
		${ECHO} "${RULE_SUBDIR}/$$f" >> ${PLIST_ADD};		\
	done
	@${ECHO} "@dirrm ${RULE_SUBDIR}" >> ${PLIST_ADD}
	@# examples are in the static PLIST
	@${INSTALL_DATA} ${WRKSRC}/procmailrc.example ${EGDIR}/
	@${INSTALL_DATA} ${WRKSRC}/rules/local.cf ${EGDIR}/
	@${INSTALL_DATA} ${FILESDIR}/netbsd_lists.cf ${EGDIR}/
	@${CHOWN} ${SHAREOWN} ${RULESDIR}/*
	@${CHGRP} ${SHAREGRP} ${RULESDIR}/*
	@${CHMOD} a=r ${RULESDIR}/*
	@{ for d in ${INSTALLATION_DIRS}; do			\
		${ECHO} "@dirrm $$d";			\
	done; } | ${SORT} -r >> ${PLIST_ADD};

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
