# $NetBSD: Makefile,v 1.12 2010/02/04 01:39:11 joerg Exp $
#

DISTNAME=	rexx-imc-1.76
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://users.comlab.ox.ac.uk/ian.collier/distribution/ \
		ftp://ftp.sai.msu.su/pub/unix/rexx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.comlab.ox.ac.uk/ian.collier/Rexx/
COMMENT=	Implementation of IBM's REXX scripting language

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1

CONFLICTS=	rexx-regina-[0-9]*

.include "../../mk/bsd.pkg.mk"
