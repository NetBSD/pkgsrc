# $NetBSD: Makefile,v 1.3 2004/02/14 17:21:52 jlam Exp $
#

DISTNAME=		gss-0.0.6
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/gss/releases/ \
			${MASTER_SITE_GNU:=gss/}

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gss/
COMMENT=		GNU Generic Security Service Library

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/gss.pc.in

INFO_FILES=		gss.info

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
