# $NetBSD: Makefile,v 1.4 2020/03/20 11:57:57 nia Exp $
#

DISTNAME=	amavisd-milter-1.6.1
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=amavisd-milter/}

MAINTAINER=	kivinen@iki.fi
HOMEPAGE=	http://amavisd-milter.sourceforge.net/
COMMENT=	Sendmail milter program for amavisd-new
LICENSE=	modified-bsd

.include "options.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-milterinc=${BUILDLINK_PREFIX.libmilter}/include
CONFIGURE_ARGS+=	--with-milterlib=${BUILDLINK_PREFIX.libmilter}/lib

RCD_SCRIPTS=	amavisd-milter

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
