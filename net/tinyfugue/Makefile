# $NetBSD: Makefile,v 1.8 2002/12/12 21:02:58 jmmv Exp $
# FreeBSD Id: Makefile,v 1.8 1998/04/11 04:21:19 jseger Exp
#

DISTNAME=	tf-40s1
PKGNAME=	tf-4.0s1
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/

MAINTAINER=	packages@NetBSD.ORG
HOMEPAGE=	http://tf.tcp.com/~hawkeye/tf/
COMMENT=	Popular programmable MUD client, with macro support and more

USE_BUILDLINK2=	YES

MAKEFILE=	${WRKSRC}/unix/Makefile
MAKE_ENV=	TFVER="${DISTNAME:S/^tf-//}"

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
