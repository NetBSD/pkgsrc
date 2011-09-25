# $NetBSD: Makefile,v 1.3 2011/09/25 19:49:25 joerg Exp $
#

DISTNAME=	fml-7.98.15-${FML_STAMP}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.fml.org/pub/fml8/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fml.org/software/fml8/index.html.en
COMMENT=	FML mailing list server development version
LICENSE=	gnu-gpl-v2 OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir
USERGROUP_PHASE=	pre-install

# development version
FML_STAMP=	20100306

GNU_CONFIGURE=	yes
USE_TOOLS=	perl:run

PLIST_SUBST+=	FML_STAMP=${FML_STAMP} EGDIR=${EGDIR}

.include "../../mk/bsd.prefs.mk"

FMLDIR?=		${VARBASE}/fml
FML_GROUP?=		fml
FML_USER?=		fml
PKG_GROUPS_VARS+=	FML_GROUP
PKG_USERS_VARS+=	FML_USER

PKG_GROUPS=		${FML_GROUP}
PKG_USERS=		${FML_USER}:${FML_GROUP}
PKG_GECOS.${FML_USER}=	FML mailing list owner

PKG_SYSCONFSUBDIR?=	fml
EGDIR=			share/examples/fml

INSTALLATION_DIRS+=	${EGDIR}

CONFS=			main.cf mime_component_filter site_default_config.cf
.for f in ${CONFS}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
OWN_DIRS_PERMS+=	${FMLDIR} ${FML_USER} ${FML_GROUP} 0755

CONFIGURE_ARGS+=	--with-sysconfdir=${PKG_SYSCONFDIR} \
			--with-mlspooldir=${FMLDIR} \
			--with-default-domain=example.net \
			--with-default-hostname=mail \
			--with-fml-owner=${FML_USER} \
			--with-fml-group=${FML_GROUP}
CONFIGURE_ENV+=		ac_cv_path_GZCAT=${GZCAT:Q} \
			ac_cv_path_PERL=${PERL5:Q}
MAKE_ENV+=		install_root=${DESTDIR} PERL=${PERL5}


PRINT_PLIST_AWK+=	/${FML_STAMP}/ \
			{ gsub(/${FML_STAMP}/, "$${FML_STAMP}"); }

CHECK_INTERPRETER_SKIP+= lib/fml/${FML_STAMP}/* \
			libexec/fml/${FML_STAMP}/loader.in

pre-configure:
	echo ${FML_STAMP} > ${WRKSRC}/.version

post-install:
.for f in ${CONFS}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/${f} ${DESTDIR}${PREFIX}/${EGDIR}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
