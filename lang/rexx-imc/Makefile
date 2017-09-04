# $NetBSD: Makefile,v 1.16 2017/09/04 18:00:56 wiz Exp $
#

DISTNAME=	rexx-imc-1.76
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://users.comlab.ox.ac.uk/ian.collier/distribution/
MASTER_SITES+=	ftp://ftp.sai.msu.su/pub/unix/rexx/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://users.comlab.ox.ac.uk/ian.collier/Rexx/
COMMENT=	Implementation of IBM's REXX scripting language

MAKE_JOBS_SAFE=	no

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1

CONFLICTS=	rexx-regina-[0-9]*

.include "../../mk/bsd.pkg.mk"
