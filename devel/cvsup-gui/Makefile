# $NetBSD: Makefile,v 1.16 2013/10/24 10:31:02 wiz Exp $

.include "${.CURDIR}/../../devel/cvsup/Makefile.common"

PKGNAME=	cvsup-gui-16.1.h
PKGREVISION=	3

CONFLICTS=	cvsup-[0-9]*

BROKEN=			Does not support DESTDIR; will be removed after 2013Q4

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
