# $NetBSD: Makefile,v 1.27 2001/03/07 07:07:11 kei Exp $
#

DISTNAME=	rpm-2.5.4
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-2.5.x/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.rpm.org/
COMMENT=	The Red Hat Package Manager

BUILD_DEPENDS+=	msgfmt:../../devel/gettext

CONFLICTS+=	rpm2cpio-*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBINTL=	yes

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/rpm
	${SED}	-e "s|@CAT@|${CAT}|g"					\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s|@MKDIR@|${MKDIR}|g"				\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
