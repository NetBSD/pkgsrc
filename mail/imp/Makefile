# $NetBSD: Makefile,v 1.7 2001/05/22 21:12:20 jlam Exp $

DISTNAME=	imp-2.2.5
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/imp/tarballs/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.horde.org/imp/
COMMENT=	Internet Messaging Program

DEPENDS+=	horde-1.2.5:../../www/horde
DEPENDS+=	php-imap>3.0.17:../../www/php4-imap

NO_CONFIGURE=	# defined

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

DOCDIR=		${PREFIX}/share/doc/imp
EGDIR=		${PREFIX}/share/examples/imp
HORDEDIR=	${PREFIX}/share/horde
IMPDIR=		${HORDEDIR}/imp

MESSAGE_SUBST+=	IMPDIR=${IMPDIR}

.include "../../mk/bsd.prefs.mk"

APACHE_SYSCONFDIR?=	${LOCALBASE}/etc/httpd
BUILD_DEFS+=		APACHE_SYSCONFDIR
MESSAGE_SUBST+=		APACHE_SYSCONFDIR=${APACHE_SYSCONFDIR}

post-extract:
	cd ${WRKSRC}/config;						\
	for file in							\
		MOTD.html header.txt html.php3 imp_module_config.php3	\
		lang.php3 mailbox.php3 menu.txt prefs.php3 trailer.txt;	\
	do								\
		${MV} $${file} $${file}.dist;				\
	done

post-patch:
	cd ${WRKSRC}/config;						\
	for file in defaults.php3.dist; do				\
		${MV} -f $${file} $${file}.orig;			\
		${SED}	-e "s|/usr/bin/ispell|${LOCALBASE}/bin/ispell|g" \
			-e "s|/usr/bin/wvHtml|${LOCALBASE}/bin/wvHTML|g" \
			-e "s|/usr/bin/xlHtml|${LOCALBASE}/bin/xlHTML|g" \
			-e "s|/bin/tar|/usr/bin/tar|g"			\
			-e "s|/usr/bin/zipinfo|${LOCALBASE}/bin/zipinfo|g" \
			$${file}.orig > $${file};			\
	done
	cd ${WRKSRC}/scripts;						\
	for file in pine2imp.pl; do					\
		${MV} -f $${file} $${file}.orig;			\
		${SED}	-e "s|/usr/bin/perl|${PERL5}|g"			\
			-e "s|/usr/local/|${LOCALBASE}/|g"		\
			$${file}.orig > $${file};			\
	done

do-build:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;
	${FIND} ${WRKSRC} -name "*.pl" -exec ${CHMOD} +x {} \;
	${FIND} ${WRKSRC} -name "*.sh" -exec ${CHMOD} +x {} \;

pre-install:
	${SED}	-e "s|@IMPDIR@|${IMPDIR}|g"				\
		${FILESDIR}/imp.conf.dist > ${WRKDIR}/imp.conf.dist
	${SED}	-e "s|@IMPDIR@|${IMPDIR:S/^${PREFIX}\///}|g"		\
		-e "s|@APACHE_SYSCONFDIR@|${APACHE_SYSCONFDIR}|g"	\
		-e "s|@CAT@|${CAT}|g"					\
		-e "s|@RM@|${RM}|g"					\
		-e "s|@RMDIR@|${RMDIR}|g"				\
		-e "s|@TRUE@|${TRUE}|g"					\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s|@IMPDIR@|${IMPDIR:S/^${PREFIX}\///}|g"		\
		-e "s|@APACHE_SYSCONFDIR@|${APACHE_SYSCONFDIR}|g"	\
		-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CHMOD@|${CHMOD}|g"				\
		-e "s|@CP@|${CP}|g"					\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${EGDIR} ${IMPDIR}
	cd ${WRKDIR}; ${INSTALL_DATA} imp.conf.dist ${EGDIR}/imp.conf
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING README docs/* ${DOCDIR}
	cd ${WRKSRC}; ${CP} -R graphics lib locale scripts templates ${IMPDIR}
	${INSTALL_DATA_DIR} ${IMPDIR}/config
	cd ${WRKSRC}/config; ${INSTALL_DATA} * ${IMPDIR}/config
	cd ${WRKSRC}; ${INSTALL_DATA} *.css *.php3 ${IMPDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${IMPDIR}
	${CHMOD} -R a-w ${IMPDIR}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
