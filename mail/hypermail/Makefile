# $NetBSD: Makefile,v 1.15 2012/01/24 09:11:06 sbd Exp $
#

DISTNAME=	hypermail-2.1.8
PKGREVISION=	2
CATEGORIES=	mail www
MASTER_SITES=	http://www.hypermail.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hypermail.org/
COMMENT=	Creates indexed, threaded HTML archives of email

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		yacc

CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-htmldir=${DESTDIR}${PREFIX}/share/doc/html/hypermail

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
