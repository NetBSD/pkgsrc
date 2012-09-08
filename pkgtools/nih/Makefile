# $NetBSD: Makefile,v 1.17 2012/09/08 17:52:49 cheusov Exp $

DISTNAME=	pkgnih-0.10.1
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/pkgnih/nih/}
CATEGORIES=	pkgtools
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/cheusov/nih/ \
		http://mova.org/~cheusov/pub/pkgnih/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/pkgnih
COMMENT=	Package manager for pkgsrc
LICENSE=	2-clause-bsd

DEPENDS+=	pkg_summary-utils>=0.58.4:../../pkgtools/pkg_summary-utils
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
REPLACE_FILES.runawk=	nih/pkg_update_plan.in nih/cmp2hr.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD || ${OPSYS} == FreeBSD || ${OPSYS} == OpenBSD || \
    ${OPSYS} == DragonFly || ${OPSYS} == MirBSD
FTP_CMD=/usr/bin/ftp
.else
FTP_CMD=${PREFIX}/bin/ftp
DEPENDS+=	tnftp-[0-9]*:../../net/tnftp
.endif

MAKE_ENV+= FTP=${FTP_CMD:Q}

.if ${OPSYS} =="SunOS" #&& empty(OS_VERSION:M5.11*)
REPLACE_SH+=	nih/nih.in nih/pkg_status.in
.endif

.include "../../devel/mk-configure/mk-c.mk"

.include "../../mk/bsd.pkg.mk"
