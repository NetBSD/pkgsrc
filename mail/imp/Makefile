# $NetBSD: Makefile,v 1.16 2001/12/02 06:56:41 jlam Exp $

DISTNAME=	imp-2.2.7
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/imp/tarballs/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.horde.org/imp/
COMMENT=	Internet Messaging Program

DEPENDS+=	horde-1.2.7:../../www/horde
DEPENDS+=	php-imap>3.0.17:../../mail/php4-imap

DOCDIR=		${PREFIX}/share/doc/imp
EGDIR=		${PREFIX}/share/examples/imp
HORDEDIR=	${PREFIX}/share/horde
IMPDIR=		${HORDEDIR}/imp

MESSAGE_SUBST+=	IMPDIR=${IMPDIR}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd

CONF_FILES=	${EGDIR}/imp.conf ${PKG_SYSCONFDIR}/imp.conf
CONF_FILES+=	${IMPDIR}/config/defaults.php3.dist			\
		${IMPDIR}/config/defaults.php3
CONF_FILES+=	${IMPDIR}/config/ldap.php3.dist				\
		${IMPDIR}/config/ldap.php3
CONF_FILES+=	${IMPDIR}/config/servers.php3.dist			\
		${IMPDIR}/config/servers.php3
SUPPORT_FILES+=	${IMPDIR}/config/MOTD.html.dist				\
		${IMPDIR}/config/MOTD.html
SUPPORT_FILES+=	${IMPDIR}/config/header.txt.dist			\
		${IMPDIR}/config/header.txt
SUPPORT_FILES+=	${IMPDIR}/config/html.php3.dist				\
		${IMPDIR}/config/html.php3
SUPPORT_FILES+=	${IMPDIR}/config/imp_module_config.php3.dist		\
		${IMPDIR}/config/imp_module_config.php3
SUPPORT_FILES+=	${IMPDIR}/config/lang.php3.dist				\
		${IMPDIR}/config/lang.php3
SUPPORT_FILES+=	${IMPDIR}/config/mailbox.php3.dist			\
		${IMPDIR}/config/mailbox.php3
SUPPORT_FILES+=	${IMPDIR}/config/menu.txt.dist				\
		${IMPDIR}/config/menu.txt
SUPPORT_FILES+=	${IMPDIR}/config/mime.php3.dist				\
		${IMPDIR}/config/mime.php3
SUPPORT_FILES+=	${IMPDIR}/config/prefs.php3.dist			\
		${IMPDIR}/config/prefs.php3
SUPPORT_FILES+=	${IMPDIR}/config/trailer.txt.dist			\
		${IMPDIR}/config/trailer.txt

post-extract:
	cd ${WRKSRC};							\
	for file in							\
		config/MOTD.html config/header.txt config/html.php3	\
		config/imp_module_config.php3	config/lang.php3	\
		config/mailbox.php3 config/menu.txt config/trailer.txt ; \
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
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f
	${FIND} ${WRKSRC} -name "*.pl" -print | ${XARGS} ${CHMOD} +x
	${FIND} ${WRKSRC} -name "*.sh" -print | ${XARGS} ${CHMOD} +x

pre-install:
	${SED}	-e "s|@IMPDIR@|${IMPDIR}|g"				\
		${FILESDIR}/imp.conf.dist > ${WRKDIR}/imp.conf.dist

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

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
