# $NetBSD: Makefile,v 1.1.1.1 1999/07/01 15:26:19 agc Exp $
#

DISTNAME=       gdb-4.18
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gdb/gdb.html

NOT_FOR_PLATFORM=	NetBSD-*-*	# In NetBSD base system

MAKE_ENV+=	CPPFLAGS=
INFO_FILES=	gdb.info gdbint.info stabs.info bfd.info
INFO_FILES+=	mmalloc.info standards.info
INSTALL_TARGET=	install install-info

do-configure:
	cd ${WRKSRC}; ./configure --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
