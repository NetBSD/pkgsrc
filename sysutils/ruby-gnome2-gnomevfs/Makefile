# $NetBSD: Makefile,v 1.9 2011/01/13 13:39:25 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnomevfs-${VERSION}
COMMENT=		Ruby binding of gnomevfs
PKGREVISION=		1
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
