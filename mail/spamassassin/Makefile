# $NetBSD: Makefile,v 1.55 2005/04/29 08:48:40 heinz Exp $

DISTNAME=	Mail-SpamAssassin-${SPAMASSASSIN_VERSION}
PKGNAME=	spamassassin-${SPAMASSASSIN_VERSION}
PKGREVISION=	# empty
SVR4_PKGNAME=	sa
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_APACHE:=spamassassin/} \
		http://spamassassin.apache.org/released/

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://spamassassin.apache.org/
COMMENT=	Mail filter to identify spam

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	p5-Net-DNS>=0.34:../../net/p5-Net-DNS
DEPENDS+=	p5-HTML-Parser>=3.31:../../www/p5-HTML-Parser
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	{p5-MIME-Base64>=2.11,perl{,-thread}>=5.8.0}:../../converters/p5-MIME-Base64
DEPENDS+=	{p5-Storable-[0-9]*,perl{,-thread}>=5.8.0}:../../devel/p5-Storable
.if ${OPSYS} != "NetBSD"
DEPENDS+=	p5-DB_File-[0-9]*:../../databases/p5-DB_File
.endif

CONFLICTS=	p5-Mail-SpamAssassin-[1-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

SPAMASSASSIN_VERSION=	3.0.3

WRKSRC=			${WRKDIR}/${DISTNAME}

PERL5_REQD+=   		5.6.1	# MakeMaker >= 5.45 needed

USE_PKGINSTALL=		YES
PKG_SYSCONFSUBDIR=	spamassassin

# Set contact address (e-mail, URL, ...) for use in spam report messages
# See "perldoc Mail::SpamAssassin::Conf" for option "report_contact" 
SPAMASSASSIN_CONTACT_ADDRESS?=	postmaster

.include "options.mk"

BUILD_DEFS+=		SPAMASSASSIN_CONTACT_ADDRESS

PLIST_ADD=		${WRKSRC}/.PLIST_ADD
PLIST_SRC=		${PKGDIR}/PLIST ${PLIST_ADD}
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/SpamAssassin/.packlist

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_DIRS=		${WRKSRC}/spamc
PERL5_CONFIGURE=	NO # we need the default "do-configure" target
PERL5_CONFIGURE_DIRS=	${WRKSRC}

MAKE_PARAMS+=		SYSCONFDIR="${PKG_SYSCONFDIR}"
MAKE_PARAMS+=		LOCALRULESDIR="${PKG_SYSCONFDIR}"
MAKE_PARAMS+=		DEFRULESDIR="${RULESDIR}"
MAKE_PARAMS+=		CONTACT_ADDRESS=${SPAMASSASSIN_CONTACT_ADDRESS:Q}

RCD_SCRIPTS=		spamd
RCD_SCRIPT_SRC.spamd=	${WRKSRC}/spamd/netbsd-rc-script.sh

EGDIR=			${PREFIX}/share/examples/spamassassin
EG_SUBDIR=		${EGDIR:S,^${PREFIX}/,,}
DOCDIR=			${PREFIX}/share/doc/spamassassin
DOC_SUBDIR=		${DOCDIR:S,^${PREFIX}/,,}
RULESDIR=		${PREFIX}/share/spamassassin
RULE_SUBDIR=		${RULESDIR:S,^${PREFIX}/,,}

CONF_FILES+=		${EGDIR}/local.cf  ${PKG_SYSCONFDIR}/local.cf	\
			${EGDIR}/init.pre  ${PKG_SYSCONFDIR}/init.pre	\
			${RULESDIR}/user_prefs.template			\
		 	${PKG_SYSCONFDIR}/user_prefs.template

INSTALLATION_DIRS+=	${EG_SUBDIR} ${DOC_SUBDIR} ${DOC_SUBDIR}/spamc	\
			${DOC_SUBDIR}/spamd

SUBST_CLASSES+=		sa2 sa3

SUBST_STAGE.sa2=	pre-configure
SUBST_FILES.sa2=	README spamd/spamd.raw
SUBST_SED.sa2=		-e s!@@PREFIX@@!${PREFIX}!g			\
			-e s!@PKG_SYSCONFDIR@!${PKG_SYSCONFDIR}!g

SUBST_STAGE.sa3=	pre-configure
SUBST_FILES.sa3=	INSTALL UPGRADE USAGE ldap/README		\
			spamc/README.qmail				\
			lib/Mail/SpamAssassin/Conf.pm spamd/README	\
			spamd/README.vpopmail sql/README sql/README.awl
SUBST_SED.sa3=		-e s!/usr/share!${PREFIX}/share!g		\
			-e s!/usr/bin!${PREFIX}/bin!g			\
			-e s!/usr/local/bin!${PREFIX}/bin!g		\
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
	@${CHMOD} a+x ${WRKSRC}/tools/convert_awl_dbm_to_sql

pre-configure: perl5-configure
	@# GNU configure needs version.h -> create it
	@cd ${WRKSRC}/spamc && ${PERL5} ./version.h.pl

post-install:
	@${TEST} -r ${PLIST_ADD} && ${RM} ${PLIST_ADD} ; :
.for f in INSTALL LICENSE README TRADEMARK UPGRADE USAGE	\
		CREDITS PACKAGING STATUS BUGS Changes 			\
		spamc/README.qmail					\
		sample-nonspam.txt sample-spam.txt spamd/README		\
		spamd/README.vpopmail
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}/$f
	@${ECHO} "${DOC_SUBDIR}/$f" >> ${PLIST_ADD}
.endfor
.for f in STATISTICS.txt STATISTICS-set1.txt STATISTICS-set2.txt	\
		STATISTICS-set3.txt
	@${INSTALL_DATA} ${WRKSRC}/rules/$f ${DOCDIR}/
	@${ECHO} "${DOC_SUBDIR}/$f" >> ${PLIST_ADD}
.endfor
.for DIR in masses sql ldap tools
	@cd ${WRKSRC};							\
	for d in `${FIND} ${DIR} -type d -print`; do			\
		${INSTALL_DATA_DIR} ${DOCDIR}/$$d;			\
	done;								\
	for f in `${FIND} ${DIR} -type f -print`; do			\
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
	@${INSTALL_DATA} ${WRKSRC}/rules/init.pre ${EGDIR}/
	@${INSTALL_DATA} ${WRKSRC}/rules/local.cf ${EGDIR}/
	@${INSTALL_DATA} ${FILESDIR}/netbsd_lists.cf ${EGDIR}/
	@${CHOWN} ${SHAREOWN} ${RULESDIR}/*
	@${CHGRP} ${SHAREGRP} ${RULESDIR}/*
	@${CHMOD} a=r ${RULESDIR}/*
	@{ for d in ${INSTALLATION_DIRS}; do				\
		${ECHO} "@dirrm $$d";					\
	done; } | ${SORT} -r >> ${PLIST_ADD};

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
