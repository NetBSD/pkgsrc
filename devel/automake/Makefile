# $NetBSD: Makefile,v 1.17 1999/05/22 16:24:09 tv Exp $
# FreeBSD Id: Makefile,v 1.5 1997/09/19 09:29:04 max Exp
#

DISTNAME=	automake-1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}

MAINTAINER=	fujimoto@oscar.elec.waseda.ac.jp
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html

DEPENDS=	autoconf-2.13:../../devel/autoconf

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PREFIX}/bin/perl
STRIPFLAG=	# none

USE_PERL5=	yes
INFO_FILES=	automake.info

.include "../../mk/bsd.pkg.mk"
