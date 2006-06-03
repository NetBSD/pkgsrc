# $NetBSD: bsd.check-vars.mk,v 1.1 2006/06/03 23:11:42 jlam Exp $
#
# This Makefile fragment is included by bsd.prefs.mk and defines some
# variables which must be defined earlier than where bsd.check.mk
# is included.
#

CHECK_SHLIBS_SUPPORTED?=	yes

USE_TOOLS+=	awk cat cmp diff echo find grep rm sed test touch true
