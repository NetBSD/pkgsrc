# $NetBSD: Makefile,v 1.13 1999/02/04 19:07:51 agc Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/05 06:56:41 tg Exp
#

DISTNAME=	teTeX-src-0.4
PKGNAME=	teTeX-0.4p8
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	systems/unix/teTeX/distrib/sources
DISTFILES=	${TETEX_SRC} ${TETEX_LIB}

PATCH_DIST_STRIP=	-p1

MAINTAINER=	br@schiele-ct.de

DEPENDS+=	dialog-0.6z:../../misc/dialog

DIST_SUBDIR=	teTeX
NO_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11=	yes
ALL_TARGET=	config clean texhash all
INSTALL_TARGET=	install ini
INFO_FILES=	latex kpathsea.info dvips.info fontname.info

TETEX_SRC=	teTeX-src-0.4pl7.tar.gz
TETEX_LIB=	teTeX-lib-0.4pl8.tar.gz
WRKLIB=		${WRKDIR}/teTeX

.if defined(CFLAGS) && ${CFLAGS} == "-O"
CFLAGS=	-O2
.endif

pre-install:
	@${RM} -f ${PREFIX}/share/texmf/ls-R
	@${RM} -f ${WRKLIB}/info/dir ${WRKLIB}/info/localdir \
		 ${WRKLIB}/info/*.orig ${WRKLIB}/info/README \
	         ${WRKLIB}/info/texinfo*
	@find ${WRKLIB}/texmf/fonts -type d -perm 1755 -exec chmod 755 {} \;
	@${INSTALL_DATA} ${WRKLIB}/info/* ${PREFIX}/info
	@${INSTALL_DATA} ${WRKLIB}/man/man1/* ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKLIB}/man/man5/* ${PREFIX}/man/man5
	@ (cd ${WRKLIB}; tar cf - texmf) | (cd ${PREFIX}/share; tar --unlink -xpf -)
	@${INSTALL_DATA} ${WRKLIB}/texmf.cnf ${PREFIX}/share/texmf/web2c

post-install:
	@chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/texmf
	@find ${PREFIX}/share/texmf/fonts/pk ${PREFIX}/share/texmf/fonts/tfm \
		-type d -print | xargs chmod 1777
	@${SETENV} PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL

.include "../../mk/bsd.pkg.mk"
