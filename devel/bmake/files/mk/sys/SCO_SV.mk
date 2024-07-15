# $Id: SCO_SV.mk,v 1.1 2024/07/15 09:10:10 jperkin Exp $

OS = SCO_SV
OS_DEF_FLAG := -D${OS}

CC  ?= gcc
CXX ?= g++
DEV_TOOLS_PREFIX ?= /usr/xdev
FC ?= gfortran
INSTALL ?= /usr/gnu/bin/install
LD ?= gcc

.include "UnixWare.mk"
