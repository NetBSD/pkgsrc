# $NetBSD: Makefile,v 1.18 2018/08/22 09:45:25 wiz Exp $
#

DISTNAME=	fml-4.0-stable-20040215
PKGNAME=	fml4-4.0.3.20040215
PKGREVISION=	13
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.fml.org/pub/fml/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fml.org/software/fml4/index-e.html
COMMENT=	FML mailing list server
LICENSE=	gnu-gpl-v2 OR artistic

DEPENDS+=	p5-Perl4-CoreLibs>=0.003:../../devel/p5-Perl4-CoreLibs

PLIST_SRC=	${PKGDIR}/PLIST
FML_DIR=	fml

NO_BUILD=	YES
USE_TOOLS+=	perl:run tar
BUILD_DEFS=	FML_DATADIR

.include "../../mk/bsd.prefs.mk"

FML_DATADIR?=	${VARBASE}/fml
FML_USER?=	fml
FML_GROUP?=	fml
PKG_GROUPS=	${FML_GROUP}
PKG_USERS=	${FML_USER}:${FML_GROUP}
PKG_SHELL.${FML_USER}=	/bin/csh

REPLACE_PERL=	databases/examples/ldap-toymodel/dump.pl \
		www/sbin/JapaneseToEnglish.pl sbin/showsystem.pl

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	sbin/makefml
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX:Q},g'
SUBST_SED.paths+=	-e 's,@FML_DATADIR@,${FML_DATADIR:Q},g'
SUBST_STAGE.paths=	pre-configure

MAKE_ENV+=		_PATH_PERL=${PERL5} HOSTNAME="fml.example.net"

CONF_FILES+=		${FML_DIR}/examples/system ${FML_DIR}/.fml/system
OWN_DIRS_PERMS+=	${FML_DATADIR} ${FML_USER} ${FML_GROUP} 0755
OWN_DIRS_PERMS+=	${FML_DATADIR}/etc ${FML_USER} ${FML_GROUP} 0750
FILES_SUBST+=		FML_DIR=${FML_DIR} FML_DATADIR=${FML_DATADIR}
PLIST_SUBST+=		FML_DIR=${FML_DIR}
MESSAGE_SUBST+=		FML_DIR=${FML_DIR}

INSTALLATION_DIRS+=	${FML_DIR}/examples

do-configure:
	${LN} -fs ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/sbin

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${PERL5} makefml install
	${MV} ${DESTDIR}${PREFIX}/${FML_DIR}/.fml/system \
		${DESTDIR}${PREFIX}/${FML_DIR}/examples
	${FIND} ${DESTDIR}${PREFIX}/${FML_DIR} -xdev -type f \
		\( -name '*.bak' -o -name '*.orig' \) -exec ${RM} -- {} \;
	${INSTALL_SCRIPT} ${PKGSRCDIR}/mk/gnu-config/config.guess \
	    ${DESTDIR}${PREFIX}/${FML_DIR}/sbin/config.guess


.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
