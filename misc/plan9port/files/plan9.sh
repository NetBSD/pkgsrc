#!/bin/sh

# Define plan9 environment.
export PLAN9=@PREFIX@/plan9
export PATH="$PATH:$PLAN9/bin"

# For the standard user. 
export home=$HOME
export user=$USER

# Set rc(1) prompt.
export H=`hostname | sed 's/\..*//'`
export prompt="$H-;  "

# Get rid of ANSI color codes.
# export TERM=vt100
# export TERM=dumb

# Default font for Plan 9 programs.
# export font=${PLAN9}/font/lucsans/typeunicode.7.font
# export font=${PLAN9}/font/lucm/unicode.9.font
export font=${PLAN9}/font/pelm/unicode.8.font

# Preferred plan9 editor.
# export editor=sam
export editor=acme

# Sane text paging.
export MANPAGER='9 p'
#PAGER='col -b'
