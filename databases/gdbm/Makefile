# $NetBSD: Makefile,v 1.26 2002/09/11 00:50:04 schmonz Exp $
# FreeBSD Id: Makefile,v 1.4 1997/01/28 08:11:23 asami Exp 
#

DISTNAME=	gdbm-1.8.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNU:=gdbm/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gdbm/gdbm.html
COMMENT=	The GNU database manager

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
INFO_FILES=		gdbm.info
TEXINFO_OVERRIDE=	YES
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

post-extract:
	${RM} -f ${WRKSRC}/gdbm.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
