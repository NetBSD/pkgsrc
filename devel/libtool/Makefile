# $NetBSD: Makefile,v 1.23 2000/10/21 22:23:00 wiz Exp $
#

DISTNAME=	libtool-1.3.5
PKGNAME=	libtool-1.3.5nb6
CATEGORIES=	devel pkgtools
MASTER_SITES=	${MASTER_SITE_GNU:=libtool/}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/libtool/libtool.html

CONFLICTS=	glibtool-*
GNU_CONFIGURE=	yes

# It seems the info-files distributed with libtool 1.3.5 are broken.
# To test, type "info libtool|" and hold down space. See it stop with a
# ``Cannot find the node "(/usr/pkg/info/libtool.info)Linking executables"''
# error. Simply making sure the info-files get re-done works here.
post-extract:
	${RM} -f ${WRKSRC}/doc/libtool.info*

test check: build
	cd ${WRKSRC} && ${MAKE} check

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MNetBSD-1.4-sparc} != "" || \
	${MACHINE_PLATFORM:MNetBSD-1.4.[12]-sparc} != ""
DEPENDS+=	c++rt0>=1.0:../../sysutils/c++rt0
.endif

.if ${OPSYS} == "NetBSD"
.if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS=	--disable-shared
.endif
.else
CONFIGURE_ARGS=	--enable-ltdl-install
.endif

.include "../../mk/bsd.pkg.mk"
