# $NetBSD: Makefile,v 1.15 2022/06/28 11:36:03 wiz Exp $

VERSION_TAG=	0.4.1.3

DISTNAME=	Unburden-Home-Dir-${VERSION_TAG}
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	-https://codeload.github.com/xtaran/unburden-home-dir/tar.gz/${VERSION_TAG}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://github.com/xtaran/unburden-home-dir
COMMENT=	Automatically unburden HOME directory from caches etc
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/unburden-home-dir-${VERSION_TAG}

DEPENDS+=	p5-Config-File-[0-9]*:../../devel/p5-Config-File
DEPENDS+=	p5-File-BaseDir-[0-9]*:../../devel/p5-File-BaseDir
DEPENDS+=	p5-File-Rsync-[0-9]*:../../net/p5-File-Rsync
DEPENDS+=	p5-File-Touch-[0-9]*:../../devel/p5-File-Touch
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-String-Expand-[0-9]*:../../textproc/p5-String-Expand
DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	lsof-[0-9]*:../../sysutils/lsof

USE_TOOLS+=	perl
REPLACE_PERL+=	bin/unburden-home-dir

USE_LANGUAGES=	# empty
NO_BUILD=	yes

DOCDIR=		share/doc/unburden-home-dir
EGDIR=		share/examples/unburden-home-dir
CONF_FILES=	${PREFIX}/${EGDIR}/unburden-home-dir.conf	\
			${PKG_SYSCONFDIR}/unburden-home-dir.conf
CONF_FILES+=	${PREFIX}/${EGDIR}/unburden-home-dir.list	\
			${PKG_SYSCONFDIR}/unburden-home-dir.list

PKG_SYSCONFSUBDIR=	unburden-home-dir
INSTALLATION_DIRS+=	bin libexec libexec/unburden-home-dir
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${EGDIR} ${DOCDIR}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-install
SUBST_MESSAGE.fix-paths=	Fixing absolute paths
SUBST_FILES.fix-paths=		bin/unburden-home-dir
SUBST_FILES.fix-paths+=		docs/unburden-home-dir.1.md
SUBST_FILES.fix-paths+=		share/common.sh
SUBST_FILES.fix-paths+=		unburden-home-dir.1
SUBST_FILES.fix-paths+=		Xsession.d/25unburden-home-dir-xdg
SUBST_FILES.fix-paths+=		Xsession.d/95unburden-home-dir
SUBST_VARS.fix-paths+=		PKG_SYSCONFDIR PREFIX

SUBST_CLASSES+=			comment-cfg
SUBST_STAGE.comment-cfg=	pre-install
SUBST_MESSAGE.comment-cfg=	Commenting out sample config file entries
SUBST_FILES.comment-cfg=	etc/unburden-home-dir.list
SUBST_SED.comment-cfg=		-E -e 's,^([^\#]),\#\1,g'

.include "../../mk/bsd.prefs.mk"

# To keep this package lightweight, leave it to the pkg updater to render
# the man page.
#
# Usage: Install devel/ruby-ronn and devel/gmake, then run
# 	`make clean ; make PKG_DEVELOPER=1 unburden-update-manpage`
# and commit the updated man file .

.if defined(PKG_DEVELOPER)

USE_TOOLS+=	gmake
DEPENDS+=	${RUBY_PKGPREFIX}-ronn-[0-9]*:../../devel/ruby-ronn

.PHONY:		unburden-update-manpage
unburden-update-manpage:	patch
	( cd ${WRKSRC} && \
	  ronn${RUBY_VER} --manual="Unburden Your Home Directory" -r \
	  --pipe < docs/unburden-home-dir.1.md > unburden-home-dir.1 )
	cp ${WRKSRC}/unburden-home-dir.1 ${PKGDIR}/files/

.include "../../lang/ruby/rubyversion.mk"

.endif # PKG_DEVELOPER

post-extract:
	cp ${PKGDIR}/files/unburden-home-dir.1 ${WRKSRC}/

do-install:
	for ff in ${WRKSRC}/docs/*.md; do \
		${INSTALL_DATA} $$ff ${DESTDIR}${PREFIX}/${DOCDIR}/ ; \
	done
	${INSTALL_MAN} ${WRKSRC}/unburden-home-dir.1 \
	               ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/unburden-home-dir \
		${DESTDIR}${PREFIX}/bin/unburden-home-dir
	${INSTALL_DATA} ${WRKSRC}/share/common.sh \
		${DESTDIR}${PREFIX}/libexec/unburden-home-dir/common.sh
	${INSTALL_DATA} ${WRKSRC}/Xsession.d/95unburden-home-dir \
		${DESTDIR}${PREFIX}/${EGDIR}/unburden-home-dir
	${INSTALL_DATA} ${WRKSRC}/Xsession.d/25unburden-home-dir-xdg \
		${DESTDIR}${PREFIX}/${EGDIR}/unburden-home-dir-xdg
	${INSTALL_DATA} ${WRKSRC}/etc/unburden-home-dir \
		${DESTDIR}${PREFIX}/${EGDIR}/unburden-home-dir.conf
	${INSTALL_DATA} ${WRKSRC}/etc/unburden-home-dir.list \
		${DESTDIR}${PREFIX}/${EGDIR}/unburden-home-dir.list

.include "../../mk/bsd.pkg.mk"
