# $NetBSD: Makefile,v 1.18 2000/06/04 17:56:16 rh Exp $
#

DISTNAME=	libtool-1.3.5
PKGNAME=	libtool-1.3.5nb3
CATEGORIES=	devel pkgtools
MASTER_SITES=	${MASTER_SITE_GNU:=libtool/}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/libtool/libtool.html

CONFLICTS=	glibtool-*
GNU_CONFIGURE=	yes

test check: build
	cd ${WRKSRC} && ${MAKE} check

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS=	--disable-shared
.endif
.else
CONFIGURE_ARGS=	--enable-ltdl-install
.endif

.include "../../mk/bsd.pkg.mk"
