# $NetBSD: Makefile,v 1.31 2003/08/09 10:38:23 seb Exp $
#

DISTNAME=	gdbm-1.8.3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU:=gdbm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gdbm/gdbm.html
COMMENT=	The GNU database manager

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
INFO_FILES=		gdbm.info
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

.include "../../mk/bsd.pkg.mk"
