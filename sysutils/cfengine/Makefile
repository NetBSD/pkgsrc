# $NetBSD: Makefile,v 1.11 2003/06/02 01:16:56 jschauma Exp $
#

DISTNAME=	cfengine-1.6.3
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.iu.hio.no/pub/cfengine/ \
		ftp://ftp.cfengine.webmotion.net/pub/cfengine/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.cfengine.org/
COMMENT=	Automate configuration and administration of large systems

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--without-pthreads

.include "../../mk/bsd.pkg.mk"
