# $NetBSD: Makefile,v 1.1.1.1 2000/07/28 14:59:04 ad Exp $
#

DISTNAME=	rio500-0.7
CATEGORIES=	audio
MASTER_SITES=	http://download.sourceforge.net/rio500/

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://rio500.sourceforge.net/

USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-devicepath=/dev --with-deviceentry=urio0

.include "../../mk/bsd.pkg.mk"
