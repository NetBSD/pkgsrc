# $NetBSD: Makefile,v 1.3 2004/02/14 17:21:38 jlam Exp $
#

DISTNAME=		libidn-0.3.3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=libidn/} \
			http://josefsson.org/libidn/releases/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/libidn/
COMMENT=		Internationalized Domain Names command line tool

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/libidn.pc.in

INFO_FILES=		libidn.info

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
