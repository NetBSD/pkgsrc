# $NetBSD: Makefile,v 1.13 1999/05/09 14:10:27 frueauf Exp $
# FreeBSD Id: Makefile,v 1.9 1997/11/12 03:24:41 obrien Exp
#

DISTNAME=	cu-sudo.v1.5.9p1
PKGNAME=	sudo-1.5.9p1
WRKSRC=		${WRKDIR}/sudo.v1.5.9p1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cs.colorado.edu/pub/sudo/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.courtesan.com/courtesan/products/sudo/

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
SKEY_OPTION=	--with-skey
.elif ${OPSYS} == "SunOS"
SKEY_OPTION=	--without-skey
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-C2 ${SKEY_OPTION} --with-nbsdops --disable-path-info

post-patch:
	cd ${WRKSRC}; for manpg in sudo.man sudoers.man visudo.man; do	\
		${MV} $$manpg $$manpg.hardcoded;			\
		${SED} -e 's|/usr/pkg|${LOCALBASE}|g' $$manpg.hardcoded > $$manpg; \
	done

post-install:
	cd ${WRKSRC} ; ${CP} sample.sudoers ${PREFIX}/etc/sudoers.example

.include "../../mk/bsd.pkg.mk"
