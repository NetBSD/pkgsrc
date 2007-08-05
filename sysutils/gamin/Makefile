# $NetBSD: Makefile,v 1.10 2007/08/05 20:03:35 tnn Exp $

DISTNAME=	gamin-0.1.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gnome.org/~veillard/gamin/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/~veillard/gamin/
COMMENT=	File alteration monitor

CONFLICTS=	fam-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--without-threads
CONFIGURE_ARGS+=	--with-html-dir=${DOCDIR:Q}

PKG_SYSCONFSUBDIR=	gamin
DOCDIR=			${PREFIX}/share/doc/gamin

SUBST_CLASSES+=		sysconfdir
SUBST_MESSAGE.sysconfdir=fixing up sysconfdir
SUBST_STAGE.sysconfdir=	pre-configure
SUBST_FILES.sysconfdir=	doc/config.html doc/gamin.html server/gam_conf.c
SUBST_SED.sysconfdir=	-e "s,/etc/gamin/,${PKG_SYSCONFDIR}/,"

SUBST_CLASSES+=		versioning
SUBST_MESSAGE.versioning=removing GNU ld(1) --version-script flag
SUBST_STAGE.versioning=	pre-configure
SUBST_FILES.versioning=	libgamin/Makefile.in
SUBST_SED.versioning=	-e 's|-Wl,--version-script.*sym.version||g'

.include "../../devel/glib2/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc; for file in *.html *.gif *.txt *.xml; do	\
		${INSTALL_DATA} $$file ${DOCDIR}/$$file;		\
	done

.include "../../mk/bsd.pkg.mk"
