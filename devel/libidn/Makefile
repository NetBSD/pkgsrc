# $NetBSD: Makefile,v 1.8 2004/07/13 16:45:47 xtraeme Exp $
#

DISTNAME=		libidn-0.5.1
CATEGORIES=		devel
MASTER_SITES=		ftp://alpha.gnu.org/pub/gnu/libidn/ \
			http://josefsson.org/libidn/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/libidn/
COMMENT=		Internationalized Domain Names command line tool

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=    libidn.pc.in

INFO_FILES=		libidn.info

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
