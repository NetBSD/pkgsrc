# $NetBSD: Makefile,v 1.12 2004/04/25 07:36:28 snj Exp $
# FreeBSD Id: Makefile,v 1.8 1998/04/11 04:21:19 jseger Exp
#

DISTNAME=	tf-40s1
PKGNAME=	tf-4.0s1
PKGREVISION=	2
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tf.tcp.com/~hawkeye/tf/
COMMENT=	Popular programmable MUD client, with macro support and more

USE_BUILDLINK3=	YES

MAKEFILE=	${WRKSRC}/unix/Makefile
MAKE_ENV=	TFVER="${DISTNAME:S/^tf-//}"

PATCH_SITES=	http://discworld.imaginary.com/external/taffyd/
PATCHFILES=	tf-40s1-mccp-patch.gz
PATCH_DIST_STRIP=-p1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
