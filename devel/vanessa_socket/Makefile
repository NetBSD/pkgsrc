# $NetBSD: Makefile,v 1.11 2023/12/19 12:43:53 zafer Exp $

DISTNAME=	vanessa_socket-0.0.10
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://projects.horms.net/projects/vanessa/download/vanessa_socket/0.0.10/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://projects.horms.net/projects/vanessa/
COMMENT=	Library that simplifies TCP/IP socket operations

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/vanessa_logger/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
