# $NetBSD: Makefile,v 1.48 2012/03/03 23:55:35 tron Exp $

DISTNAME=		elm2.5.8
PKGNAME=		elm-2.5.8
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		http://www.instinct.org/elm/files/tarballs/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.instinct.org/elm/
COMMENT=		ELM Mail User Agent (without ME extensions)

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

DEPENDS+=		metamail>=2.7:../../mail/metamail

CONFLICTS+=		mm-[0-9]*
CONFLICTS+=		elm-me-[0-9]*

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-d
CONFIGURE_ENV+=		DESTDIR=${DESTDIR}
USE_TOOLS+=		nroff

INSTALLATION_DIRS=	share/nls/C

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "Darwin")
LIBC=			/usr/lib/libSystem.dylib
.else
LIBC=			/usr/lib/libc.so
.endif

SPECIAL_PERMS+=		bin/elm ${ROOT_USER} mail 2755

pre-configure:
	${CP} ${FILESDIR}/config.sh ${WRKSRC}/config.sh.orig
	${SED} -e 's:@PREFIX@:${PREFIX}:g' \
	  -e 's:@DESTDIR@:${DESTDIR}:g' \
	  -e 's:@LOCALBASE@:${LOCALBASE}:g' \
	  -e 's:@LIBC@:${LIBC}:g' \
	  ${WRKSRC}/config.sh.orig > ${WRKSRC}/config.sh
	${MV} ${WRKSRC}/nls/LANGS ${WRKSRC}/nls/LANGS.tmpl
	${SED} -e 's:__PREFIX:'${PREFIX}':g' < ${WRKSRC}/nls/LANGS.tmpl > ${WRKSRC}/nls/LANGS

post-install:
	${LN} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/frm.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nfrm.1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
