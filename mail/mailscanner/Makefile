# $NetBSD: Makefile,v 1.13 2009/06/14 22:58:04 joerg Exp $
#

DISTNAME=		MailScanner-4.30.3-2
PKGNAME=		mailscanner-4.30.3.2
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		http://www.sng.ecs.soton.ac.uk/mailscanner/files/4/tar/

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.mailscanner.info/
COMMENT=		Powerful spam/virus filter with many options

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/MailScanner-4.30.3

PKG_SYSCONFSUBDIR=	MailScanner

DEPENDS+=		p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=		p5-Convert-BinHex-[0-9]*:../../converters/p5-Convert-BinHex
DEPENDS+=		p5-Net-CIDR>=0.09:../../devel/p5-Net-CIDR
DEPENDS+=		p5-MIME-tools>=0:../../mail/p5-MIME-tools
DEPENDS+=		tnef>=1.0:../../mail/tnef

NO_BUILD=		YES
USE_TOOLS+=		perl:run bash:run
REPLACE_BASH+=		 bin/update_virus_scanners
REPLACE_PERL+=		bin/MailScanner
REPLACE_PERL+=		lib/panda-wrapper lib/rav-wrapper lib/*-autoupdate

DOCSDIR=		${LOCALBASE}/share/doc/MailScanner
EGDIR=			${LOCALBASE}/share/examples/MailScanner
LIBDIR=			${LOCALBASE}/lib/MailScanner
LIBEXECDIR=		${LOCALBASE}/libexec/MailScanner

OWN_DIRS=		${PKG_SYSCONFDIR}/CustomFunctions
OWN_DIRS+=		${PKG_SYSCONFDIR}/rules

PLIST_SUBST+=		DOCSDIR=${DOCSDIR:Q}
PLIST_SUBST+=		EGDIR=${EGDIR:Q}
PLIST_SUBST+=		LIBDIR=${LIBDIR:Q}
PLIST_SUBST+=		LIBEXECDIR=${LIBEXECDIR:Q}

PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

MS_CONFIG_FILES=	filename.rules.conf \
			filetype.rules.conf spam.assassin.prefs.conf \
			spam.lists.conf virus.scanners.conf \
			rules/bounce.rules rules/spam.whitelist.rules

CONF_FILES+=		${EGDIR}/MailScanner.conf ${PKG_SYSCONFDIR}/MailScanner.conf
.for _f_ in ${MS_CONFIG_FILES}
CONF_FILES+=		${EGDIR}/${_f_} ${PKG_SYSCONFDIR}/${_f_}
.endfor

RCD_SCRIPTS=		mailscanner

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	bin/MailScanner etc/MailScanner.conf
SUBST_FILES.paths+=	etc/virus.scanners.conf bin/update_virus_scanners
SUBST_FILES.paths+=	lib/MailScanner/ConfigDefs.pl
SUBST_SED.paths=	-e s,/opt/MailScanner/lib/MailScanner/CustomFunctions,${PKG_SYSCONFDIR}/CustomFunctions,g
SUBST_SED.paths+=	-e s,/opt/MailScanner/lib,${LIBDIR},g
SUBST_SED.paths+=	-e s,/opt/MailScanner/etc/reports,${EGDIR}/reports,g
SUBST_SED.paths+=	-e s,/opt/MailScanner/etc,${PKG_SYSCONFDIR},g
SUBST_SED.paths+=	-e s,/opt/MailScanner/var/MailScanner.pid,/var/run/MailScanner.pid,g
SUBST_SED.paths+=	-e s,/opt/MailScanner/bin,${PREFIX}/bin,g

.include "../../mk/bsd.prefs.mk"

# XXX this could use some improvement
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		sendmail
SUBST_STAGE.sendmail=	post-patch
SUBST_FILES.sendmail=	bin/MailScanner etc/MailScanner.conf
SUBST_FILES.sendmail+=	etc/virus.scanners.conf bin/update_virus_scanners
SUBST_FILES.sendmail+=	lib/MailScanner/ConfigDefs.pl
SUBST_SED.sendmail=	-e s,/usr/lib/sendmail,/usr/sbin/mailwrapper,g
.endif

SUBST_CLASSES+=		systemdefs
SUBST_STAGE.systemdefs=	post-patch
SUBST_FILES.systemdefs=	lib/MailScanner/SystemDefs.pm
SUBST_SED.systemdefs=	-e s,/bin/cat,${CAT},g
SUBST_SED.systemdefs=	-e s,/bin/cp,${CP},g
SUBST_SED.systemdefs=	-e s,/bin/rm,${RM},g
# we can't use sed from pkgsrc as it won't be registered as a
# dependency. XXX tools.mk needs a way to tell us about this dependency.
.if empty(SED:M${LOCALBASE}*)
SUBST_SED.systemdefs=	-e s,/bin/sed,${SED},g
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

# get rid of CVS backup files
post-extract:
	cd ${WRKSRC} && ${RM} -f */.#*

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/rules
	${INSTALL_SCRIPT} ${WRKSRC}/bin/MailScanner ${DESTDIR}${PREFIX}/bin

	${INSTALL_LIB_DIR} ${DESTDIR}${LIBEXECDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/update_virus_scanners ${DESTDIR}${LIBEXECDIR}
	cd ${WRKSRC}/lib && ${FIND} . -name "*-autoupdate" -exec ${INSTALL_SCRIPT} '{}' ${DESTDIR}${LIBEXECDIR} \;
	cd ${WRKSRC}/lib && ${FIND} . -name "*-wrapper" -exec ${INSTALL_SCRIPT} '{}' ${DESTDIR}${LIBEXECDIR} \;

	${INSTALL_DATA} ${WRKSRC}/etc/MailScanner.conf ${DESTDIR}${EGDIR}/MailScanner.conf
.for _f_ in ${MS_CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${_f_} ${DESTDIR}${EGDIR}
.endfor
	cd ${WRKSRC}/etc/rules && ${INSTALL_DATA} \
		EXAMPLES README spam.whitelist.rules bounce.rules \
		${DESTDIR}${EGDIR}/rules
	cd ${WRKSRC}/etc && ${FIND} reports -type d -exec ${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/'{}' \;
	cd ${WRKSRC}/etc && ${FIND} reports -type f ! -name "*.orig" -exec ${INSTALL_DATA} '{}' ${DESTDIR}${EGDIR}/'{}' \;

	${INSTALL_LIB_DIR} ${DESTDIR}${LIBDIR}
	${INSTALL_LIB_DIR} ${DESTDIR}${LIBDIR}/MailScanner
	${INSTALL_SCRIPT} ${WRKSRC}/lib/MailScanner.pm ${DESTDIR}${LIBDIR}
	cd ${WRKSRC}/lib/MailScanner && ${FIND} . -name "*.pm" -exec ${INSTALL_DATA} '{}' ${DESTDIR}${LIBDIR}/MailScanner \;
	cd ${WRKSRC}/lib/MailScanner && ${FIND} . -name "*.pl" -exec ${INSTALL_DATA} '{}' ${DESTDIR}${LIBDIR}/MailScanner \;

	${INSTALL_DATA_DIR} ${DESTDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} * -type d -exec ${INSTALL_DATA_DIR} ${DESTDIR}${DOCSDIR}'/{}' \;
	cd ${WRKSRC}/docs && ${FIND} * -type f -exec ${INSTALL_DATA} '{}' ${DESTDIR}${DOCSDIR} \;
	cd ${WRKSRC}/docs/man && ${INSTALL_MAN} MailScanner.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	cd ${WRKSRC}/docs/man && ${INSTALL_MAN} MailScanner.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

post-install:
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${ECHO} bin/MailScanner >> ${PLIST_SRC}
	${ECHO} man/man5/MailScanner.conf.5 >> ${PLIST_SRC}
	${ECHO} man/man8/MailScanner.8 >> ${PLIST_SRC}
.for _dir_ in ${DOCSDIR} ${EGDIR} ${LIBDIR} ${LIBEXECDIR}
	${FIND} ${DESTDIR}${_dir_} \( -type f -o -type l \) -print \
		| ${SORT} | ${SED} -e "s,${DESTDIR}${PREFIX}/,,g" \
		>> ${PLIST_SRC}
.endfor

.include "../../mk/bsd.pkg.mk"
