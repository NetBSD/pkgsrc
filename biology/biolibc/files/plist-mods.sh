#!/bin/sh -e

# Plugin for local changes to PLIST folling make print-PLIST
sed -i'' -e 's|^man/man3/BL_|${PLIST.cs}&|' PLIST.new
