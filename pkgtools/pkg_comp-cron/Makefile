# $NetBSD: Makefile,v 1.1 2017/02/17 21:27:38 jmmv Exp $

DISTNAME=	pkg_comp-cron-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Configures periodic pkgsrc binary package builds
LICENSE=	modified-bsd

DEPENDS=		pkg_comp>=2.0:../../pkgtools/pkg_comp

BUILD_DEFS=		VARBASE
DEINSTALL_TEMPLATES=	INSTALL
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}

PKG_COMP_USER?=		${REAL_ROOT_USER}
PKG_COMP_GROUP?=	${REAL_ROOT_GROUP}
PKG_COMP_HOME?=		${VARBASE}/pkg_comp

EGDIR=		${PREFIX}/share/examples/pkg_comp-cron
OWN_DIRS_PERMS=	${PKG_COMP_HOME} ${PKG_COMP_USER} ${PKG_COMP_GROUP} 755
CONF_FILES=	${EGDIR}/list.txt ${PKG_COMP_HOME}/list.txt
CONF_FILES+=	${EGDIR}/pkg_comp.conf ${PKG_COMP_HOME}/pkg_comp.conf

BUILD_SUBST+=	-e 's,@BUILDBASE@,${PKG_COMP_HOME},g'
BUILD_SUBST+=	-e 's,@EGDIR@,${EGDIR},g'
BUILD_SUBST+=	-e 's,@PKG_COMP_EGDIR@,${PREFIX}/share/examples/pkg_comp,g'
BUILD_SUBST+=	-e 's,@PREFIX@,${PREFIX},g'
FILES_SUBST+=	BUILDBASE=${PKG_COMP_HOME}
FILES_SUBST+=	EGDIR=${EGDIR}
FILES_SUBST+=	PKG_COMP_HOME=${PKG_COMP_HOME}
FILES_SUBST+=	PKG_COMP_USER=${PKG_COMP_USER}
FILES_SUBST+=	PKG_COMP_EGDIR=${PREFIX}/share/examples/pkg_comp
FILES_SUBST+=	SANDBOXCTL_EGDIR=${PREFIX}/share/examples/sandboxctl
MESSAGE_SUBST+=	EGDIR=${EGDIR}
MESSAGE_SUBST+=	PKG_COMP_HOME=${PKG_COMP_HOME}
MESSAGE_SUBST+=	PKG_COMP_USER=${PKG_COMP_USER}

.include "../../mk/bsd.prefs.mk"

# Configure the default pkg_comp.conf on a platform basis, providing
# reasonable defaults.  The user has to review the installed file anyway
# so it is not strictly necessary to make these "perfect" -- but good
# defaults will help in getting started.
.if ${OPSYS} == "Darwin"
# Xcode ships with git only, not cvs, so default to git to simplify the
# bootstrapping process.
BUILD_SUBST+=	-e 's,@FETCH_VCS@,git,g'
# Since macOS Sierra (11.12), /usr is a protected tree to which apps
# cannot write even as root.  Default to somewhere else; because pkg_comp
# requires privileges to run, /opt/pkg is a reasonable location.
BUILD_SUBST+=	-e 's,@LOCALBASE@,/opt/pkg,g'
BUILD_SUBST+=	-e 's,@SYSCONFDIR@,/opt/pkg/etc,g'
BUILD_SUBST+=	-e 's,@VARBASE@,/opt/pkg/var,g'
.else
BUILD_SUBST+=	-e 's,@FETCH_VCS@,cvs,g'
BUILD_SUBST+=	-e 's,@LOCALBASE@,/usr/pkg,g'
BUILD_SUBST+=	-e 's,@SYSCONFDIR@,/etc,g'
BUILD_SUBST+=	-e 's,@VARBASE@,/var,g'
.endif

INSTALLATION_DIRS=	share/examples/pkg_comp-cron

do-build:
.for file in list.txt pkg_comp.conf
	${SED} ${BUILD_SUBST} <${FILESDIR}/${file} >${WRKSRC}/${file}
.endfor

do-install:
.for file in list.txt pkg_comp.conf
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${EGDIR}/
.endfor

.include "../../mk/bsd.pkg.mk"
