# $NetBSD: Makefile,v 1.23 2001/06/21 02:47:27 jlam Exp $
# FreeBSD Id: Makefile,v 1.4 1997/01/28 08:11:23 asami Exp 
#

DISTNAME=	gdbm-1.8.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU:=gdbm/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gdbm/gdbm.html
COMMENT=	The GNU database manager

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
INFO_FILES=		gdbm.info

post-extract:
	${RM} -f ${WRKSRC}/gdbm.info

.include "../../mk/bsd.pkg.mk"
