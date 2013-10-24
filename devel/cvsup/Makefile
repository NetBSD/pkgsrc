# $NetBSD: Makefile,v 1.17 2013/10/24 10:31:02 wiz Exp $

.include "${.CURDIR}/../../devel/cvsup/Makefile.common"

PKGNAME=	cvsup-16.1.h
PKGREVISION=	3

M3FLAGS+=	-DNOGUI

CONFLICTS=	cvsup-{bin,gui}-[0-9]*

BROKEN=			Does not support DESTDIR; will be removed after 2013Q4

.include "../../mk/bsd.pkg.mk"
