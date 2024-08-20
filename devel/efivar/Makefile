# $NetBSD: Makefile,v 1.1 2024/08/20 15:29:32 bsiegert Exp $

DISTNAME=		efivar-38
CATEGORIES=		devel
# The project is Linux-oriented, using fork with BSD-specific changes so that
# patches are manageable and can be potentially sent upstream.
#
# The fork also uses unreleased changes as some of them fix build on systems
# that don't use glibc.
MASTER_SITES=		${MASTER_SITE_GITHUB:=3mdeb/}
GITHUB_PROJECT=		efivar
GITHUB_TAG=		bsd-v1

MAINTAINER=		sergii.dmytruk@3mdeb.com
HOMEPAGE=		https://github.com/rhboot/efivar
COMMENT=		Tools and libraries to work with EFI
LICENSE=		gnu-lgpl-v2.1 # or later

# Depends on EFI and relevant API in the kernel
ONLY_FOR_PLATFORM=	*-*-x86_64

USE_TOOLS+=		gmake

# Specify lib directory name.
MAKE_FLAGS=		LIBDIR=${PREFIX}/lib
# Override man directory default of prefix/share/man.
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}
# Instruct dynamic linker to give preference to /usr/pkg/lib.
MAKE_FLAGS+=		SOFLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
