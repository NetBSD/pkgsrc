# $NetBSD: Makefile,v 1.3 2010/06/13 22:45:25 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnomevfs-${VERSION}
COMMENT=		Ruby binding of gnomevfs
PKGREVISION=		1
CATEGORIES=		sysutils

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gnomevfs

USE_TOOLS+=		pkg-config

do-test:
	${RUN} cd ${WRKSRC}/gnomevfs/tests; \
	for t in  test*.rb; do \
		${SETENV} ${TEST_ENV} ${RUBY} -I ${WRKSRC}/gnomevfs/src/lib -I ${WRKSRC}/gnomevfs/src $$t; \
	done

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
