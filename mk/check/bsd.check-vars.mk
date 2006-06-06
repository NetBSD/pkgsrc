# $NetBSD: bsd.check-vars.mk,v 1.2 2006/06/06 15:28:52 jlam Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.check.mk is included.
#

CHECK_SHLIBS_SUPPORTED?=	yes

USE_TOOLS+=	awk cat cmp diff echo find grep rm sed test touch true
