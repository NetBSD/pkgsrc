# $NetBSD: Makefile,v 1.4 2011/07/30 10:46:01 cheusov Exp $

DISTNAME=	pkgnih-0.8.0
PKGNAME=	${DISTNAME:S/pkgnih/nih/}
CATEGORIES=	pkgtools
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/cheusov/nih/ \
		http://mova.org/~cheusov/pub/pkgnih/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	https://github.com/cheusov/pkgnih
COMMENT=	Package manager for pkgsrc
LICENSE=	2-clause-bsd

DEPENDS+=	pkg_summary-utils>=0.53.2:../../pkgtools/pkg_summary-utils
DEPENDS+=	digest-[0-9]*:../../pkgtools/digest
DEPENDS+=	pkg_install>=20100915:../../pkgtools/pkg_install

BUILD_DEPENDS+=		mk-configure>=0.21.0:../../devel/mk-configure

CONFLICTS=		pkg_status-[0-9]*
SUPERSEDES=		pkgnih-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		all all-doc
INSTALL_TARGET=		install install-doc

EGDIR=			${PREFIX}/share/examples/nih

CONF_FILES=		${EGDIR}/nih.conf \
			${PKG_SYSCONFDIR}/nih/config

MAKE_DIRS+=		${PKG_SYSCONFDIR}/nih

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	.*runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	nih/pkg_update_plan.in

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}

MAKE_PROGRAM=		mkcmake

.include "../../mk/bsd.pkg.mk"
