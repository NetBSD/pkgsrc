# $NetBSD: Makefile,v 1.8 2010/02/11 23:30:22 joerg Exp $
#

DISTNAME=		nget-0.27.1
PKGREVISION=		1
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nget/}

MAINTAINER=		joel@carnat.net
HOMEPAGE=		http://nget.sourceforge.net/
COMMENT=		Command line nntp file grabber

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-pcre
CONFIGURE_ARGS+=	--with-popt

EGDIR=			${PREFIX}/share/examples/nget
MESSAGE_SUBST+=		EGDIR=${EGDIR}

INSTALLATION_DIRS=	share/nget share/examples/nget
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-install:
	for f in COPYING Changelog FAQ README TODO; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DESTDIR}${PREFIX}/share/nget; done
	${INSTALL_DATA} ${WRKSRC}/.ngetrc ${DESTDIR}${EGDIR}/dot.ngetrc

.include "../../converters/uulib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
