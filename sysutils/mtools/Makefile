# $NetBSD: Makefile,v 1.6 1998/04/15 10:38:49 agc Exp $
#

DISTNAME=	mtools-3.8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
#MASTER_SITES=	ftp://ftp.cs.uni-bonn.de/pub/gnu/

MAINTAINER=	is@netbsd.org

BUILD_DEPENDS=  ${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=    ${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		mattrib.1 mbadblocks.1 mcd.1 mcopy.1 mdel.1 mdeltree.1 mdir.1 \
		mformat.1 mkmanifest.1 mlabel.1 mmd.1 mmount.1 mmove.1 mrd.1 \
		mread.1 mren.1 mtoolstest.1 mtools.1 mtype.1 mwrite.1 mzip.1

MAN5=		mtools.5

post-install:
	${PREFIX}/bin/install-info ${PREFIX}/info/mtools.info ${PREFIX}/info/dir

.include "../../mk/bsd.pkg.mk"
