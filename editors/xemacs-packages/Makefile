# $NetBSD: Makefile,v 1.4 1999/08/23 09:23:03 tron Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1999/06/22 22:16:53 gj Exp

DISTNAME=	xemacs-packages
PKGNAME=	xemacs-packages-1.1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs/packages/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/packages/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/packages/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/packages/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/packages/
DISTFILES=	xemacs-base-1.30-pkg.tar.gz xemacs-devel-1.21-pkg.tar.gz \
		c-support-1.12-pkg.tar.gz cc-mode-1.15-pkg.tar.gz \
		debug-1.10-pkg.tar.gz dired-1.06-pkg.tar.gz \
		edit-utils-1.41-pkg.tar.gz efs-1.15-pkg.tar.gz \
		fsf-compat-1.06-pkg.tar.gz mail-lib-1.24-pkg.tar.gz \
		mailcrypt-2.02-pkg.tar.gz mule-base-1.32-pkg.tar.gz \
		net-utils-1.12-pkg.tar.gz os-utils-1.15-pkg.tar.gz \
		prog-modes-1.21-pkg.tar.gz psgml-1.14-pkg.tar.gz \
		sgml-1.05-pkg.tar.gz sh-script-1.10-pkg.tar.gz \
		text-modes-1.21-pkg.tar.gz time-1.08-pkg.tar.gz \
		vc-1.19-pkg.tar.gz viper-1.17-pkg.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xemacs.org/

DEPENDS+=	xemacs-21.1.6:../xemacs

DIST_SUBDIR=	xemacs
EXTRACT_ONLY=	# empty
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

do-install:
	@${MKDIR} ${PREFIX}/lib/xemacs/xemacs-packages
.for DISTFILE in ${DISTFILES}
	@${ECHO} -n "Extracting ${DISTFILE} ... "
	@${GTAR} xCzf ${PREFIX}/lib/xemacs/xemacs-packages \
	  ${_DISTDIR}/${DISTFILE}
	@${ECHO} "done"
.endfor

.include <../../mk/bsd.pkg.mk>
