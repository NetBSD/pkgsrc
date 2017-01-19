# $NetBSD: Makefile,v 1.19 2017/01/19 18:52:16 agc Exp $
#

DISTNAME=	hypermail-2.3.0
CATEGORIES=	mail www
MASTER_SITES=	${HOMEPAGE}
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=hypermail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hypermail-project.org/
COMMENT=	Creates indexed, threaded HTML archives of email
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGBASE}

GNU_CONFIGURE=		yes
USE_TOOLS+=		yacc

LDFLAGS+=		-liconv

CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-htmldir=${DESTDIR}${PREFIX}/share/doc/html/hypermail

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
