# $NetBSD: Makefile,v 1.7 2009/12/09 12:27:28 obache Exp $

DISTNAME=	packit-1.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://packit.sourceforge.net/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packit.sourceforge.net/
COMMENT=	Network auditing tool with the ability to manipulate IP traffic

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-libpcap-includes=${BUILDLINK_PREFIX.libpcap}/include
CONFIGURE_ARGS+=	--with-libpcap-libraries=${BUILDLINK_PREFIX.libpcap}/lib

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
