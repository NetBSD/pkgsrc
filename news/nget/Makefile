# $NetBSD: Makefile,v 1.2 2004/10/03 00:18:02 tv Exp $
#

DISTNAME=		nget-0.27
PKGREVISION=	1
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nget/}

MAINTAINER=		Joel CARNAT <joel@carnat.net>
HOMEPAGE=		http://nget.sourceforge.net/
COMMENT=		Command line nntp file grabber

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-pcre
CONFIGURE_ARGS+=	--with-popt

EGDIR=			${PREFIX}/share/examples/nget
MESSAGE_SUBST+=		EGDIR=${EGDIR}

INSTALLATION_DIRS=	share/nget share/examples/nget

post-install:
	for f in COPYING Changelog FAQ README TODO; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${PREFIX}/share/nget; done
	${INSTALL_DATA} ${WRKSRC}/.ngetrc ${EGDIR}/dot.ngetrc

.include "../../converters/uulib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
