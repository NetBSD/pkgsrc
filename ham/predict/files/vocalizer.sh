#!/bin/sh

trap 'kill -- $$' EXIT SIGINT

WAVPATH="@PREFIX@/share/predict/vocalizer"
PLAYBIN="@PREFIX@/bin/play"

playwav()
{
    "${PLAYBIN}" -q -V1 "$@"
}

playfile()
{
    case $1 in
        0) playwav "${WAVPATH}/zero.wav" ;;
        1) playwav "${WAVPATH}/one.wav" ;;
        2) playwav "${WAVPATH}/two.wav" ;;
        3) playwav "${WAVPATH}/three.wav" ;;
        4) playwav "${WAVPATH}/four.wav" ;;
        5) playwav "${WAVPATH}/five.wav" ;;
        6) playwav "${WAVPATH}/six.wav" ;;
        7) playwav "${WAVPATH}/seven.wav" ;;
        8) playwav "${WAVPATH}/eight.wav" ;;
        9) playwav "${WAVPATH}/nine.wav" ;;
        10) playwav "${WAVPATH}/ten.wav" ;;
        11) playwav "${WAVPATH}/eleven.wav" ;;
        12) playwav "${WAVPATH}/twelve.wav" ;;
        13) playwav "${WAVPATH}/thirteen.wav" ;;
        14) playwav "${WAVPATH}/fourteen.wav" ;;
        15) playwav "${WAVPATH}/fifteen.wav" ;;
        16) playwav "${WAVPATH}/sixteen.wav" ;;
        17) playwav "${WAVPATH}/seventeen.wav" ;;
        18) playwav "${WAVPATH}/eighteen.wav" ;;
        19) playwav "${WAVPATH}/nineteen.wav" ;;
        20) playwav "${WAVPATH}/twenty.wav" ;;
        30) playwav "${WAVPATH}/thirty.wav" ;;
        40) playwav "${WAVPATH}/forty.wav" ;;
        50) playwav "${WAVPATH}/fifty.wav" ;;
        60) playwav "${WAVPATH}/sixty.wav" ;;
        70) playwav "${WAVPATH}/seventy.wav" ;;
        80) playwav "${WAVPATH}/eighty.wav" ;;
        90) playwav "${WAVPATH}/ninety.wav" ;;
        *) playwav "${WAVPATH}/${1}.wav" ;;
    esac
}

saynumber()
{
    case $(($1 / 100)) in
        [1-9]) playfile $(($1 / 100))
           playfile hundred ;;
    esac
    case $(($1 % 100 / 10)) in
        [2-9]) playfile $(($1 % 100 / 10 * 10)) ;;
    esac
    if [ $1 = 0 ]; then
        playfile $1
    elif [ $(($1 % 100)) -lt 20 -a $(($1 % 100)) -gt 0 ]; then
        playfile $(($1 % 100))
    elif [ $(($1 % 100 % 10)) != 0 ]; then
        playfile $(($1 % 100 % 10))
    fi
}

if [ $# = 1 ]; then
    case $1 in
        eclipse)
            playfile alarm
            playfile eclipse
            ;;
        sunlight)
            playfile alarm
            playfile sunlight
            ;;
        los)
            playfile los
            ;;
    esac
elif [ $# -gt 1 ]; then
    playfile intro
    saynumber "${1}"
    playfile azimuth
    saynumber "${2}"
    playfile elevation
    if [ "$3" = "+" ]; then
        playfile approaching
    elif [ "$3" = "-" ]; then
        playfile receding
    fi
    if [ "$4" == "V" ]; then
        playfile visible
    fi
fi
exit 0
