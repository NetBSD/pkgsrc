# $NetBSD: Makefile,v 1.3 2001/02/16 14:38:25 wiz Exp $
#

DISTNAME=       gdb-4.18
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gdb/gdb.html
COMMENT=	symbolic debugger for multiple language frontends

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

MAKE_ENV+=	CPPFLAGS=
INFO_FILES=	gdb.info gdbint.info stabs.info bfd.info
INFO_FILES+=	mmalloc.info standards.info
INSTALL_TARGET=	install install-info

do-configure:
	cd ${WRKSRC}; ./configure --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
