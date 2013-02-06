# $NetBSD: Makefile,v 1.9 2013/02/06 19:31:00 jperkin Exp $

DISTNAME=	packit-1.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://packit.sourceforge.net/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packit.sourceforge.net/
COMMENT=	Network auditing tool with the ability to manipulate IP traffic

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-libpcap-includes=${BUILDLINK_PREFIX.libpcap}/include
CONFIGURE_ARGS+=	--with-libpcap-libraries=${BUILDLINK_PREFIX.libpcap}/lib

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
