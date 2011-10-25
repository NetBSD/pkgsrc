# $NetBSD: Makefile,v 1.6 2011/10/25 07:32:19 wiz Exp $
#

DISTNAME=	awl-${LIBAWL_VERSION}
PKGNAME=	${PHP_PKG_PREFIX}-libawl-${LIBAWL_VERSION}
LIBAWL_VERSION=	0.49
CATEGORIES=	devel
MASTER_SITES=	http://debian.mcmillan.net.nz/packages/awl/

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	http://andrew.mcmillan.net.nz/projects/awl/
COMMENT=	PHP Andrew's Web Libraries
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/php/phpversion.mk"

.if ${PKG_PHP_VERSION} == "5"
DEPENDS+=       php>=5.2.0<5.3:../../lang/php5
.endif
DEPENDS+=	${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-gettext-[0-9]*:../../devel/php-gettext

INSTALLATION_DIRS=	${LIBAWLDIR} ${LIBAWLDIR}/inc ${LIBAWLDIR}/dba

do-install:
	cd ${WRKSRC}/dba;					\
       	for f in *; do						\
		${INSTALL_DATA} "$$f"				\
		    ${DESTDIR}${PREFIX}/${LIBAWLDIR}/dba;	\
	done;

	cd ${WRKSRC}/inc;					\
       	for f in *; do						\
		${INSTALL_DATA} "$$f"				\
		    ${DESTDIR}${PREFIX}/${LIBAWLDIR}/inc;	\
	done;

.include "../../devel/php-libawl/Makefile.common"
.include "../../mk/bsd.pkg.mk"
