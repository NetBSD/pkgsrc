# $NetBSD: Makefile,v 1.11 2023/12/19 12:42:07 zafer Exp $

DISTNAME=	vanessa_logger-0.0.8
CATEGORIES=	devel
MASTER_SITES=	https://projects.horms.net/projects/vanessa/download/vanessa_logger/0.0.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://projects.horms.net/projects/vanessa/
COMMENT=	Library that provides a generic logging layer

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

# The SunPro compiler does not understand __FUNCTION__, as well as
# __func__. So __FILE__ is the nearest replacement.
.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Msunpro)
SUBST_CLASSES+=			__function__
SUBST_STAGE.__function__=	pre-configure
SUBST_FILES.__function__=	libvanessa_logger/vanessa_logger.h
SUBST_SED.__function__=		-e "s|__FUNCTION__|__FILE__|g"
.endif

.include "../../mk/bsd.pkg.mk"
