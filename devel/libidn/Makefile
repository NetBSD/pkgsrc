# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 19:17:10 xtraeme Exp $
#

DISTNAME=		libidn-0.3.3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=libidn/} \
			http://josefsson.org/libidn/releases/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/libidn/
COMMENT=		Internationalized Domain Names command line tool

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/libidn.pc.in

INFO_FILES=		libidn.info

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/libgetopt/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
