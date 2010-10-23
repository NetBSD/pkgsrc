# $NetBSD: Makefile,v 1.6 2010/10/23 12:45:12 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnomevfs-${VERSION}
COMMENT=		Ruby binding of gnomevfs
CATEGORIES=		sysutils

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gnomevfs-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gnomevfs

do-test:
	${RUN} cd ${WRKSRC}/gnomevfs/tests; \
	for t in  test*.rb; do \
		${SETENV} ${TEST_ENV} ${RUBY} -I ${WRKSRC}/gnomevfs/src/lib -I ${WRKSRC}/gnomevfs/src $$t; \
	done

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
