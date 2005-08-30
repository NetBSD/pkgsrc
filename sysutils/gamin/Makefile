# $NetBSD: Makefile,v 1.3 2005/08/30 23:24:33 jlam Exp $

DISTNAME=	gamin-0.1.5
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gnome.org/~veillard/gamin/sources/

CONFLICTS=	fam-[0-9]*

MAINTAINER=	jlam@NetBSD.org
COMMENT=	file alteration monitor
HOMEPAGE=	http://www.gnome.org/~veillard/gamin/

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--without-threads
CONFIGURE_ARGS+=	--with-html-dir=${DOCDIR}

# glib2/buildlink3.mk pulls in gettext-lib/buildlink3.mk, but the gamin
# libraries don't need to be linked against -lintl automatically.
#
BROKEN_GETTEXT_DETECTION=      no

PKG_SYSCONFSUBDIR=	gamin
DOCDIR=			${PREFIX}/share/doc/gamin

SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	pre-configure
SUBST_FILES.sysconfdir=	doc/config.html doc/gamin.html server/gam_conf.c
SUBST_SED.sysconfdir=	-e "s,/etc/gamin/,${PKG_SYSCONFDIR}/,"


.include "../../devel/glib2/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc; for file in *.html *.gif *.txt *.xml; do	\
		${INSTALL_DATA} $$file ${DOCDIR}/$$file;		\
	done

.include "../../mk/bsd.pkg.mk"
